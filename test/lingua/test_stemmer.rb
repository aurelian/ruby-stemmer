# frozen_string_literal: true

require 'helper'

class TestStemmer < Minitest::Test
  def test_stemmer_creation
    assert_kind_of ::Lingua::Stemmer, ::Lingua::Stemmer.new
  end

  def test_exceptions
    assert_raises ::Lingua::StemmerError do
      # invalid encoding for language
      ::Lingua::Stemmer.new language: 'ro', encoding: 'ISO_8859_1'
    end
    assert_raises ::Lingua::StemmerError do
      # invalid language
      ::Lingua::Stemmer.new language: 'cat'
    end
  end

  def test_latin
    ::Lingua::Stemmer.new language: 'latin', encoding: 'ISO_8859_1'
  rescue StandardError => e
    flunk "Expected latin to be loaded but failed with #{e}"
  end

  def test_stem
    stemmer = ::Lingua::Stemmer.new(language: 'en', encoding: 'UTF_8')
    assert_equal stemmer.stem('obnoxious'), 'obnoxi'
    assert_equal stemmer.stem('personalities'), 'person'
  end

  def test_string_stemmer
    assert_equal ::Lingua.stemmer('installation', language: 'en'), 'instal'
    stemmer = ::Lingua.stemmer('installation', language: 'fr') do |word|
      assert_equal word, 'install'
    end
    assert_kind_of ::Lingua::Stemmer, stemmer
    assert_equal stemmer.encoding, Encoding::UTF_8
  end

  def test_array_stemmer
    results = ::Lingua.stemmer(%w[one two], language: 'de', encoding: 'ISO_8859_1')
    assert_equal 2, results.size
    assert_kind_of Array, results
  end

  def test_array_stemmer_issue_22
    results = ::Lingua.stemmer(['one'], language: 'de', encoding: 'ISO_8859_1')
    assert_equal 1, results.size
    assert_kind_of Array, results
  end

  def test_stemmer_subclass
    assert_raises(RuntimeError) do
      Class.new(Lingua::Stemmer) do
        def native_init(a, b); end
      end.new.stem('cow')
    end
  end

  def test_default_encoding_option
    if RUBY_VERSION >= '1.9'
      assert_equal ::Lingua::Stemmer.new.encoding, Encoding::UTF_8
    else
      assert_equal ::Lingua::Stemmer.new.encoding, 'UTF_8'
    end
  end

  def test_different_encoding_options
    assert_equal ::Lingua::Stemmer.new(encoding: 'ISO_8859_1').encoding, Encoding::ISO_8859_1
    assert_equal ::Lingua::Stemmer.new(encoding: 'UTF-8').encoding, Encoding::UTF_8
    assert_equal ::Lingua::Stemmer.new(encoding: 'utf-8').encoding, Encoding::UTF_8
    assert_equal ::Lingua::Stemmer.new(encoding: :ISO_8859_1).encoding, Encoding::ISO_8859_1
    assert_equal ::Lingua::Stemmer.new(encoding: Encoding::UTF_8).encoding, Encoding::UTF_8
  end

  def test_string_encoding
    word = 'așezare'

    stem = ::Lingua.stemmer(word, language: 'ro', encoding: 'UTF_8')
    assert_equal word.encoding, stem.encoding

    s = ::Lingua::Stemmer.new(language: 'ro', encoding: 'UTF_8')
    assert_equal s.stem(word).encoding, word.encoding

    stem = ::Lingua.stemmer('installation', language: 'fr', encoding: 'ISO-8859-1')
    assert_equal stem.encoding, Encoding::ISO_8859_1
  end

  def test_lithuanian_stem
    stemmer = ::Lingua::Stemmer.new(language: 'lt')
    %w[
      kompiuteris kompiuterio kompiuteriui kompiuteriu kompiuteri
    ].each do |word|
      assert_equal stemmer.stem(word), 'kompiuter'
    end
  end
end
