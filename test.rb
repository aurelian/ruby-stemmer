#!/usr/bin/env ruby

#
# $Id: test.rb 21 2008-04-30 10:57:37Z aurelian $
#

$kcode = "utf-8"

require "stemmer.so"

#puts "installation".stem

# puts ">>> test 1."
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
