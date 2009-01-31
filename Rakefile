#
# $Id: Rakefile 22 2008-05-09 23:49:43Z aurelian $
#

require 'rubygems'
require 'rake'
require 'echoe'

Echoe.new('ruby-stemmer', '0.5.3') do |p|
    p.description    = "Stemmer implementation to ruby using libstemmer_c. Working with ruby 1.9.1"
    p.url            = "http://github.com/yury/ruby-stemmer"
    p.author         = "Yury Korolev"
    p.email          = "yury.korolev@gmail.com"
    p.extensions     = ["extconf.rb"]
    p.ignore_pattern = ["*.o", "**/*.o", "stemwords", "*.bundle", "*.a", "*.so"]
    p.development_dependencies = []
    p.runtime_dependencies = []
    p.has_rdoc = true
end

rm_rf 'Makefile'

PKG_FILES = FileList[
  'extconf.rb',
  'ruby-stemmer.c',
  'test.rb',
  '[A-Z]*',
  'libstemmer_c/**/*'
]

PKG_FILES.exclude('*.o')
PKG_FILES.exclude('**/*.o')
PKG_FILES.exclude('stemwords')
PKG_FILES.exclude('*.bundle')
PKG_FILES.exclude('*.a')
PKG_FILES.exclude('*.so')

task :clean do
  `rm -rf Makefile mkmf.log ruby-stemmer.o stemmer.bundle stemmer.so`
  `cd libstemmer_c && make clean && cd ../`
end

