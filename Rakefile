require 'rubygems'
require 'rake'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |gem|
    gem.name = "ruby-stemmer"
    gem.summary = %Q{Expose libstemmer_c to Ruby.}
    gem.description = %Q{Expose the bundled libstemmer_c library to Ruby.}
    gem.email = "oancea@gmail.com"
    gem.homepage = "http://github.com/aurelian/ruby-stemmer"
    gem.authors = ["Aurelian Oancea", "Yury Korolev"]
    gem.extensions = ["ext/lingua/extconf.rb"]
    gem.rubyforge_project = "ruby-stemmer"
    gem.files = FileList['lib/**/*.rb', 'README.rdoc', 'MIT-LICENSE', 'VERSION', 'Rakefile', 'libstemmer_c/**/*', 'ext/**/*', 'test/**/*']
    %w(ext/lingua/*.so ext/lingua/*.bundle ext/lingua/Makefile ext/lingua/mkmf.log ext/lingua/*.o libstemmer_c/**/*.o).each do | f |
      gem.files.exclude f
    end
    # gem.ignore_pattern = ["*.o", "**/*.o", "stemwords", "*.bundle", "*.a", "*.so", "Makefile"]
    # gem is a Gem::Specification... see http://www.rubygems.org/read/chapter/20 for additional settings
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

desc "Cleans the project"
task :clean do
  `cd ext/lingua && rm -rf Makefile mkmf.log stemmer.o stemmer_native.bundle stemmer.so; cd ../../`
  `cd libstemmer_c && make clean && cd ../`
end

desc "Builds the extension"
task :ext => :clean do
  `cd ext/lingua/ && ruby extconf.rb && make && cd ../../`
end

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "Ruby-Stemmer #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
  rdoc.rdoc_files.include('ext/lingua/stemmer.c')
  rdoc.rdoc_files.include('MIT-LICENSE')
end
