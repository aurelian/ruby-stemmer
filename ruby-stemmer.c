//
// $Id: ruby-stemmer.c 20 2008-04-29 20:59:56Z aurelian $
//

#include "ruby.h"
#include <libstemmer.h>

#define GetStemmer(obj, sb_data) {\
  Data_Get_Struct(obj, struct sb_stemmer_data, sb_data);\
}

VALUE rb_mLingua;
VALUE rb_cStemmer;

struct sb_stemmer_data {
  struct sb_stemmer * stemmer;
  const char * lang;
  const char * enc;
};

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
rb_stemmer_init(int argc, VALUE *argv, VALUE self) { 
  VALUE roptions, rlang, renc;

  struct sb_stemmer * stemmer;
  struct sb_stemmer_data *sb_data;

  rb_scan_args(argc, argv, "01", &roptions);
  
  if(argc > 0) {
    Check_Type(roptions, T_HASH);
    if((rlang = rb_hash_aref(roptions, ID2SYM(rb_intern("language")))) != Qnil) {
      Check_Type(rlang, T_STRING);
    } else {
      rlang = rb_str_new2("en");
    }
    if((renc = rb_hash_aref(roptions, ID2SYM(rb_intern("encoding")))) != Qnil) {
      Check_Type(renc, T_STRING);
    } else {
      renc = rb_str_new2("UTF_8");
    }
  } else {
    rlang = rb_str_new2("en");
    renc  = rb_str_new2("UTF_8");
  }
  
  stemmer = sb_stemmer_new( RSTRING_PTR(rlang), RSTRING_PTR(renc) );
  if (stemmer == 0) {
    // printf(">>[libstemmer]: got a null stemmer!\n");
    if (renc == 0 ) {
      rb_raise(rb_eRuntimeError, "Language %s not available for stemming", RSTRING_PTR(rlang));
      exit(1);
    } else {
      rb_raise(rb_eRuntimeError, "Language %s not available for stemming in encoding %s", 
                    RSTRING_PTR(rlang), RSTRING_PTR(renc));
      exit(1);
    }
  }
  
  sb_data = ALLOC(struct sb_stemmer_data);
  DATA_PTR(self) = sb_data;
  sb_data->stemmer= stemmer;
  sb_data->lang   = RSTRING_PTR(rlang);
  sb_data->enc    = RSTRING_PTR(renc);

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
  struct sb_stemmer_data * sb_data;
  const  sb_symbol * stemmed;
  VALUE s_word = rb_String(word);
  GetStemmer(self, sb_data);
  stemmed = sb_stemmer_stem(sb_data->stemmer, (sb_symbol *)RSTRING_PTR(s_word), RSTRING_LEN(s_word));
  return rb_str_new2((char *)stemmed);
}

/*
 * Document-method: length
 * call-seq: length
 *
 * Gets the length of the last stemmed word
 *
 *   require 'lingua/stemmer'
 *   s = Lingua::Stemmer.new
 *   s.stem "installation"
 *   s.length # ==> 6
 */ 
static VALUE
rb_stemmer_length(VALUE self) {
  struct sb_stemmer_data * sb_data;
  int length;
  GetStemmer(self, sb_data);
  length = sb_stemmer_length(sb_data->stemmer);
  return INT2FIX(length);
}

static void
sb_stemmer_free(struct sb_stemmer_data * sb_data)
{
  sb_stemmer_delete(sb_data->stemmer);
}

static VALUE
sb_stemmer_alloc(VALUE klass)
{
  return Data_Wrap_Struct(klass, 0, sb_stemmer_free, 0);
}

/*
 * ruby-stemmer, ruby extension to SnowBall API using libstemmer_c
 */
void Init_stemmer() {
  rb_mLingua = rb_define_module("Lingua");
  rb_cStemmer = rb_define_class_under(rb_mLingua, "Stemmer", rb_cObject);
  rb_define_alloc_func(rb_cStemmer, sb_stemmer_alloc);
  rb_define_method(rb_cStemmer, "initialize", rb_stemmer_init, -1);
  rb_define_method(rb_cStemmer, "stem", rb_stemmer_stem, 1);
  rb_define_method(rb_cStemmer, "length", rb_stemmer_length, 0);
}

