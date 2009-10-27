#!/usr/bin/env ruby
# coding:utf-8

require "stemmer.so"

puts ">>> test 1."
stemmer = Lingua::Stemmer.new()
puts stemmer.stem("installation")
puts stemmer.length
puts stemmer.stem("popularity")

puts ">>> test 2."
stemmer = Lingua::Stemmer.new(:language => 'en')
puts stemmer.stem("obnoxious")

puts ">>> test 3."
stemmer = Lingua::Stemmer.new(:encoding => 'UTF_8')
puts stemmer.stem("găinațul")

puts ">>> test 4."
stemmer = Lingua::Stemmer.new(:language => 'en', :encoding => 'UTF_8')
puts stemmer.stem("personalities")

puts ">>> test 5."
stemmer = Lingua::Stemmer.new(:encoding => 'UTF_8', :language => 'ro')
puts stemmer.stem("întrebător");

puts ">>> test 6."
stemmer = Lingua::Stemmer.new(:encoding => 'UTF_8', :language => 'ro')
puts stemmer.stem(["one", "two"]);

puts ">>> test 7."
stemmer = Lingua::Stemmer.new(:encoding => 'UTF_8', :language => 'ro')
puts stemmer.stem(nil);
