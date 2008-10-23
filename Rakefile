#
# $Id: Rakefile 22 2008-05-09 23:49:43Z aurelian $
#

require 'rubygems'
require 'rake'
require 'rake/gempackagetask'

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

spec = Gem::Specification.new do | s |
  s.name = 'ruby-stemmer'
  s.version = '0.5.1'
  s.summary = "Stemmer implementation to ruby using SnowBall API from libstemmer_c."
  s.description = <<-EOF
    Stemmer implementation to ruby using libstemmer_c.
  EOF

  s.files = PKG_FILES.to_a
  s.extensions << "extconf.rb"
  s.has_rdoc = true
  s.rdoc_options << '--title' <<  'Ruby-Stemmer' << 
    '--exclude' << 'libstemmer_c' << '--exclude' << 'extconf.rb' <<
    '--exclude' << 'test.rb' << '--inline-source' << 'ruby-stemmer.c' << 'README' << '--main' << 'README'
  s.author = "Aurelian Oancea"
  s.email = "aurelian@locknet.ro"
  s.homepage = "http://nrr.rubyforge.org"
  s.rubyforge_project = "nrr"
end

pt = Rake::GemPackageTask.new(spec) do |p|
  p.need_tar = true
  p.need_zip = true
end

task :default do
  puts "Ok"
end

task :clean do
  `rm -rf Makefile mkmf.log ruby-stemmer.o stemmer.bundle stemmer.so`
  `cd libstemmer_c && make clean && cd ../`
end

