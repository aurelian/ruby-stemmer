require 'rubygems'
require 'bundler/setup'

require 'rdoc/task'
require 'rake/testtask'
require 'bundler/gem_tasks'
require 'rake/extensiontask'
require 'rubygems/package_task'

CLOBBER.include('libstemmer_c/**/*.o')

GEMSPEC = Gem::Specification.load('ruby-stemmer.gemspec')

Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = true
end

Rake::ExtensionTask.new('ruby-stemmer', GEMSPEC) do |ext|
  ext.lib_dir = File.join(*['lib', 'lingua', ENV['FAT_DIR']].compact)
  ext.ext_dir = File.join 'ext', 'lingua'
  ext.cross_compile = true
  ext.cross_platform = ['i386-mswin32-60', 'i386-mingw32']
  ext.name = 'stemmer_native'
end

Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ''
  rdoc.rdoc_dir = 'rdoc'
  rdoc.options << '--charset' << 'utf-8'
  rdoc.title = "Ruby-Stemmer #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
  rdoc.rdoc_files.include('ext/lingua/stemmer.c')
  rdoc.rdoc_files.include('MIT-LICENSE')
end

task default: %i[clobber compile test]
