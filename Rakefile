require 'rubygems'
require 'rake'

begin
  require 'jeweler'
  JEWLER = Jeweler::Tasks.new do |gem|
    gem.name = "ruby-stemmer"
    gem.version = File.read(File.expand_path(File.join(File.dirname(__FILE__),"VERSION"))).strip!
    gem.summary = %Q{Expose libstemmer_c to Ruby.}
    gem.description = %Q{Expose the bundled libstemmer_c library to Ruby.}
    gem.email = "oancea@gmail.com"
    gem.homepage = "http://github.com/aurelian/ruby-stemmer"
    gem.authors = ["Aurelian Oancea", "Yury Korolev"]
    gem.extensions = ["ext/lingua/extconf.rb"]
    gem.rubyforge_project = "ruby-stemmer"
    gem.files = FileList['lib/**/*.rb', 'README.rdoc', 'MIT-LICENSE', 'VERSION', 'Rakefile', 'libstemmer_c/**/*', 'ext/**/*', 'test/**/*']
    %w(ext/lingua/*.so ext/lingua/*.bundle ext/lingua/Makefile ext/lingua/mkmf.log ext/lingua/*.o libstemmer_c/**/*.o libstemmer_c/stemwords).each do | f |
      gem.files.exclude f
    end
  end
  Jeweler::GemcutterTasks.new
  Jeweler::RubyforgeTasks.new do |rubyforge|
    rubyforge.doc_task = "rdoc"
  end
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: sudo gem install jeweler"
end

require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = true
end

begin
  require 'rcov/rcovtask'
  Rcov::RcovTask.new do |test|
    test.libs << 'test'
    test.pattern = 'test/**/test_*.rb'
    test.verbose = true
  end
rescue LoadError
  task :rcov do
    abort "RCov is not available. In order to run rcov, you must: sudo gem install spicycode-rcov"
  end
end

task :test => :check_dependencies

task :default => :test

gem 'rake-compiler', '>= 0.4.1'
require "rake/extensiontask"

CLOBBER.include("libstemmer_c/**/*.o")

Rake::ExtensionTask.new(JEWLER.gemspec.name, JEWLER.gemspec) do |ext|
  ext.lib_dir = File.join(*['lib', 'lingua', ENV['FAT_DIR']].compact)
  ext.ext_dir = File.join 'ext', 'lingua'
  ext.cross_compile = true
  ext.name    = 'stemmer_native'
end

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""
  rdoc.rdoc_dir = 'rdoc'
  rdoc.options << '--charset' << 'utf-8'
  rdoc.title = "Ruby-Stemmer #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
  rdoc.rdoc_files.include('ext/lingua/stemmer.c')
  rdoc.rdoc_files.include('MIT-LICENSE')
end
