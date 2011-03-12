# encoding: utf-8
require 'helper'

class TestStemmer < Test::Unit::TestCase

  def test_stemmer_creation
    assert_kind_of ::Lingua::Stemmer, ::Lingua::Stemmer.new
  end

  def test_exceptions
    assert_raise ::Lingua::StemmerError do
      # invalid encoding for language
      ::Lingua::Stemmer.new :language => "ro", :encoding => "ISO_8859_1"
    end
    assert_raise ::Lingua::StemmerError do
      # invalid language
      ::Lingua::Stemmer.new :language => "cat"
    end
  end

  def test_latin
    assert_nothing_raised do
      ::Lingua::Stemmer.new :language => "latin", :encoding => "ISO_8859_1"
    end
  end

  def test_stem
    s= ::Lingua::Stemmer.new(:language => "en", :encoding => "UTF_8")
    assert_equal s.stem("obnoxious"), "obnoxi"
    assert_equal s.stem("personalities"), "person"
  end

  def test_string_stemmer
    assert_equal ::Lingua.stemmer("installation", :language => "en"), "instal"
    stemmer= ::Lingua.stemmer("installation", :language => "fr") do | word |
      assert_equal word, "install"
    end
    assert_kind_of ::Lingua::Stemmer, stemmer

    if RUBY_VERSION >= '1.9'
      assert_equal stemmer.encoding, Encoding::UTF_8
    else
      assert_equal stemmer.encoding, "UTF_8"
    end
  end

  def test_array_stemmer
    results= ::Lingua.stemmer(["one", "two"], :language => "de", :encoding => "ISO_8859_1")
    assert_equal 2, results.size
    assert_kind_of Array, results
  end

  def test_stemmer_subclass
    assert_raises(RuntimeError) do
      Class.new(Lingua::Stemmer) {
        def native_init a, b; end
      }.new.stem('cow')
    end
  end

  def test_default_encoding_option
    if RUBY_VERSION >= '1.9'
      assert_equal ::Lingua::Stemmer.new.encoding, Encoding::UTF_8
    else
      assert_equal ::Lingua::Stemmer.new.encoding, "UTF_8"
    end
  end

  def test_different_encoding_options
    if RUBY_VERSION >= '1.9'
      assert_equal ::Lingua::Stemmer.new(:encoding => "ISO_8859_1").encoding, Encoding::ISO_8859_1
      assert_equal ::Lingua::Stemmer.new(:encoding => "UTF-8").encoding, Encoding::UTF_8
      assert_equal ::Lingua::Stemmer.new(:encoding => "utf-8").encoding, Encoding::UTF_8
      assert_equal ::Lingua::Stemmer.new(:encoding => :ISO_8859_1).encoding, Encoding::ISO_8859_1
      assert_equal ::Lingua::Stemmer.new(:encoding => Encoding::UTF_8).encoding, Encoding::UTF_8
    else
      assert_equal ::Lingua::Stemmer.new(:encoding => "ISO_8859_1").encoding, "ISO_8859_1"
      assert_equal ::Lingua::Stemmer.new(:encoding => "UTF-8").encoding, "UTF_8"
      assert_equal ::Lingua::Stemmer.new(:encoding => "utf-8").encoding, "UTF_8"
      assert_equal ::Lingua::Stemmer.new(:encoding => :ISO_8859_1).encoding, "ISO_8859_1"
    end
  end

  if RUBY_VERSION >= '1.9'
    def test_string_encoding
      word = "așezare"

      stem = ::Lingua.stemmer(word, :language => "ro", :encoding => "UTF_8")
      assert_equal word.encoding, stem.encoding

      s = ::Lingua::Stemmer.new(:language => "ro", :encoding => "UTF_8")
      assert_equal s.stem(word).encoding, word.encoding

      stem = ::Lingua.stemmer("installation", :language => "fr", :encoding => "ISO-8859-1")
      assert_equal stem.encoding, Encoding::ISO_8859_1
    end
  end

end
