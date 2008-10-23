--
$Id: README 19 2008-01-08 12:25:57Z aurelian $
++

== About

ruby-stemmer, an extension to ruby using SnowBall API stemmer implementation libstemmer_c.

This package includes libstemmer_c library from http://snowball.tartarus.org/dist/libstemmer_c.tgz published under the terms of BSD License.

For details about libstemmer_c read libstemmer_c/README or http://snowball.tartarus.org.

author: Aurelian Oancea, aurelian at locknet dot ro

licence: MIT, see MIT-LICENSE for details

:include: MIT-LICENSE

== Install

I) Using RubyGems

  $ gem install ruby-stemmer

II) From tarball

Use sudo or run as root if you get Permission Deny issues

Compile libstemmer_c and generate the Makefile:

  $ ruby extconf.rb

Compile the library:

  $ make

Test:

  $ ./test.rb

Install it:

  $ make install

Run the last command as root or with sudo if you get permission deny problems

== Usage

see test.rb

== API

  module Lingua
    class Steemer

      # creates a new Steemer,
      # defaults: language => en, encoding => UTF_8
      # pass :language or :encoding to change them 
      def initialize
      end
    
      # stemms the word
      def stem(word)
      end
    
      # gets the length of the last stemmed word
      # same as: 
      # word = Lingua::Steemer.new.stem("installation") # ==> install (string)
      # word.length # ==> 6 (int)
      def length
      end
    end
  end

== Todo

* Add (Array of Hashes) Lingua::Stemmer.list to list available languages/encodings
* Windows?

