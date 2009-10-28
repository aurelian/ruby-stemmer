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
    assert_equal stemmer.encoding, "UTF_8"
  end

  def test_array_stemmer
    results= ::Lingua.stemmer(["one", "two"], :language => "de", :encoding => "ISO_8859_1")
    assert_equal 2, results.size
    assert_kind_of Array, results
  end

end
