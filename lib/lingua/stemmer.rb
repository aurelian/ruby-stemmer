if RUBY_PLATFORM =~/(mswin|mingw)/i
  require "lingua/#{RUBY_VERSION.sub(/\.\d+$/, '')}/stemmer_native"
else
  require 'lingua/stemmer_native'
end

module Lingua
  def self.stemmer(o, options={})
    stemmer = Stemmer.new(options)

    words = Array(o).map { |e| e.to_s }

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
    results.length == 1 ? results[0] : results
  end

  class Stemmer
    VERSION = File.read(File.expand_path(File.join(File.dirname(__FILE__), "..", "..", "VERSION"))).strip!

    attr_reader :language
    attr_reader :encoding

    # Creates a new Stemmer, pass <tt>:language</tt> and <tt>:encoding</tt>
    # as arguments to change encoding or language, otherwise english with UTF_8
    # will be used
    #
    #   require 'lingua/stemmer'
    #   s = Lingua::Stemmer.new :language => 'fr'
    #
    def initialize(options={})
      @language = (options[:language] || 'en').to_s
      @encoding = (options[:encoding] || 'UTF_8').to_s

      if RUBY_VERSION >= "1.9"
        if not @encoding.is_a?(Encoding)
          @encoding = Encoding.find(@encoding.gsub("_", "-"))
        end
      else
        @encoding = @encoding.upcase.gsub("-", "_")
      end

      native_init(@language, native_encoding(@encoding))
    end

  private
    def native_encoding(enc)
      RUBY_VERSION >= "1.9" ? enc.name.gsub('-', '_') : enc
    end
  end
end
