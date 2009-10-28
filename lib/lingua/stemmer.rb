require 'lingua/stemmer_native'

module Lingua

  def self.stemmer(o, options={})
    _stemmer= Stemmer.new({:language => "en", :encoding => "UTF_8"}.merge(options))
    words= o.kind_of?(Array)? o.map{|e|e.to_s} : [o.to_s]
    results = [] unless block_given?
    words.each do | word |
      result = _stemmer.stem(word)
      if block_given?
        yield result
      else
        results << result
      end
    end
    return (results.length == 1)? results[0] : results unless block_given?
    _stemmer
  end

  class Stemmer
    VERSION = File.read(File.expand_path(File.join(File.dirname(__FILE__), "..", "..", "VERSION")))
  end
end
