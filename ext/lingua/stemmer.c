#include "ruby.h"
#include <libstemmer.h>


#ifdef HAVE_RUBY_ENCODING_H

#include <ruby/encoding.h>

#define ENCODED_STR_NEW2(str, encoding) \
  ({ \
   VALUE _string = rb_str_new2((const char *)str); \
   int _enc = rb_enc_get_index(encoding); \
   rb_enc_associate_index(_string, _enc); \
   _string; \
   })

#else

#define ENCODED_STR_NEW2(str, encoding) \
  rb_str_new2((const char *)str)

#endif


VALUE rb_mLingua;
VALUE rb_cStemmer;
VALUE rb_eStemmerError;

/*
 * Document-method: new
 * call-seq: Lingua::Stemmer.new
 *
 * Creates a new Stemmer, pass <tt>:language</tt> and <tt>:encoding</tt> as arguments 
 * to change encoding or language, otherwise english with UTF_8 will be used
 *   
 *   require 'lingua/stemmer'
 *   s = Lingua::Stemmer.new :language => 'fr'
 */ 
static VALUE 
rb_stemmer_init(VALUE self, VALUE rlang, VALUE renc) { 
  struct sb_stemmer * stemmer;

  Data_Get_Struct(self, struct sb_stemmer, stemmer);

  // In case someone sends() this method, free up the old one
  if(stemmer) sb_stemmer_delete(stemmer);

  stemmer = sb_stemmer_new( RSTRING_PTR(rlang), RSTRING_PTR(renc) );
  if (!stemmer) {
    if (!RTEST(renc)) {
      rb_raise(rb_eStemmerError,
          "Language %s not available for stemming", RSTRING_PTR(rlang));
    } else {
      rb_raise(rb_eStemmerError,
          "Language %s not available for stemming in encoding %s", 
                    RSTRING_PTR(rlang), RSTRING_PTR(renc));
    }
  }
  
  DATA_PTR(self) = stemmer;

  return self;
}

/*
 * Document-method: stem
 * call-seq: stem
 *
 * Stems a word
 *   
 *   require 'lingua/stemmer'
 *   s = Lingua::Stemmer.new
 *   s.stem "installation" # ==> install
 */ 
static VALUE
rb_stemmer_stem(VALUE self, VALUE word) {
  struct sb_stemmer * stemmer;

  Data_Get_Struct(self, struct sb_stemmer, stemmer);
  if(!stemmer) rb_raise(rb_eRuntimeError, "Stemmer is not initialized");

  VALUE s_word = rb_String(word);
  const sb_symbol * stemmed = sb_stemmer_stem(stemmer,
      (sb_symbol *)RSTRING_PTR(s_word),
      RSTRING_LEN(s_word)
  );

  VALUE rb_enc = rb_iv_get(self, "@encoding");
  return ENCODED_STR_NEW2((char *)stemmed, rb_enc);
}

static void
sb_stemmer_free(struct sb_stemmer * stemmer)
{
  if(stemmer) sb_stemmer_delete(stemmer);
}

static VALUE
sb_stemmer_alloc(VALUE klass)
{
  return Data_Wrap_Struct(klass, 0, sb_stemmer_free, 0);
}

/*
 * Ruby-Stemmer, Ruby extension to SnowBall API using libstemmer_c
 */
void Init_stemmer_native() {
  rb_mLingua = rb_define_module("Lingua");
  rb_cStemmer = rb_define_class_under(rb_mLingua, "Stemmer", rb_cObject);
  rb_define_alloc_func(rb_cStemmer, sb_stemmer_alloc);
  rb_eStemmerError = rb_define_class_under(rb_mLingua, "StemmerError", rb_eException);
  rb_define_private_method(rb_cStemmer, "native_init", rb_stemmer_init, 2);
  rb_define_method(rb_cStemmer, "stem", rb_stemmer_stem, 1);
}

