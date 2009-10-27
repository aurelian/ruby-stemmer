require 'rubygems'
require 'rake'
require 'echoe'

Echoe.new('ruby-stemmer', '0.5.5') do |p|
    p.description    = "Stemmer implementation to ruby using libstemmer_c."
    p.url            = "http://github.com/aurelian/ruby-stemmer"
    p.author         = "Aurelian Oancea, Yury Korolev"
    p.email          = "oancea@gmail.com, yury.korolev@gmail.com"
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

desc "Cleans the workspace"
task :clean do
  `rm -rf Makefile mkmf.log ruby-stemmer.o stemmer.bundle stemmer.so`
  `cd libstemmer_c && make clean && cd ../`
end

