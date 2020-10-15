# coding: utf-8

lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'lingua/version'

Gem::Specification.new do |s|
  s.name = 'ruby-stemmer'
  s.version = Lingua::Stemmer::VERSION

  s.platform = Gem::Platform::RUBY
  s.required_ruby_version = '>= 2.4.0'

  s.require_paths = ['lib']
  s.authors = ['Aurelian Oancea', 'Yury Korolev']

  s.description = 'Expose the bundled libstemmer_c library to Ruby.'
  s.email = 'oancea@gmail.com'
  s.extensions = ['ext/lingua/extconf.rb']
  s.extra_rdoc_files = ['README.rdoc']
  s.files = `git ls-files`.split("\n")
  s.homepage = 'http://github.com/aurelian/ruby-stemmer'
  s.licenses = ['MIT']
  s.summary = 'Expose libstemmer_c to Ruby.'

  s.add_development_dependency 'minitest', '~> 5.14'
  s.add_development_dependency 'rake-compiler', '~> 1.1'
end
