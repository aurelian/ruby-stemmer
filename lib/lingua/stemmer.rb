# frozen_string_literal: true

if RUBY_PLATFORM.match?(/(mswin|mingw)/i)
  require "lingua/#{RUBY_VERSION.sub(/\.\d+$/, '')}/stemmer_native"
else
  require 'lingua/stemmer_native'
end

require 'lingua/version'

module Lingua
  def self.stemmer(o, options = {})
    stemmer = Stemmer.new(options)

    words = Array(o).map(&:to_s)

    results = []
    words.each do |word|
      result = stemmer.stem(word)
      if block_given?
        yield result
      else
        results << result
      end
    end

    return stemmer if block_given?

    o.is_a?(String) ? results[0] : results
  end

  class Stemmer
    attr_reader :language
    attr_reader :encoding

    # Creates a new Stemmer, pass <tt>:language</tt> and <tt>:encoding</tt>
    # as arguments to change encoding or language, otherwise english with UTF_8
    # will be used
    #
    #   require 'lingua/stemmer'
    #   s = Lingua::Stemmer.new language: 'fr'
    #
    def initialize(options = {})
      @language = (options[:language] || 'en').to_s
      @encoding = (options[:encoding] || 'UTF_8').to_s

      @encoding = Encoding.find(@encoding.tr('_', '-'))

      native_init(@language, native_encoding(@encoding))
    end

    private

    def native_encoding(enc)
      enc.name.tr('-', '_')
    end
  end
end
