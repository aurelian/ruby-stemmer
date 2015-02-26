# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "lingua/version"

Gem::Specification.new do |s|
  s.name = "ruby-stemmer"
  s.version = Lingua::Stemmer::VERSION

  s.platform    = Gem::Platform::RUBY
  s.required_ruby_version = ">= 1.8.7"

  s.require_paths = ["lib"]
  s.authors = ["Aurelian Oancea", "Yury Korolev"]

  s.description = "Expose the bundled libstemmer_c library to Ruby."
  s.email = "oancea@gmail.com"
  s.extensions = ["ext/lingua/extconf.rb"]
  s.has_rdoc = true
  s.extra_rdoc_files = [
    "README.rdoc"
  ]
  s.files = [
    "MIT-LICENSE",
    "README.rdoc",
    "Rakefile",
    "ext/lingua/extconf.rb",
    "ext/lingua/stemmer.c",
    "lib/lingua/stemmer.rb",
    "libstemmer_c/MANIFEST",
    "libstemmer_c/Makefile",
    "libstemmer_c/Makefile.windows",
    "libstemmer_c/README",
    "libstemmer_c/examples/stemwords.c",
    "libstemmer_c/include/libstemmer.h",
    "libstemmer_c/libstemmer/libstemmer.c",
    "libstemmer_c/libstemmer/libstemmer_utf8.c",
    "libstemmer_c/libstemmer/modules.h",
    "libstemmer_c/libstemmer/modules.txt",
    "libstemmer_c/libstemmer/modules_utf8.h",
    "libstemmer_c/libstemmer/modules_utf8.txt",
    "libstemmer_c/mkinc.mak",
    "libstemmer_c/mkinc_utf8.mak",
    "libstemmer_c/runtime/api.c",
    "libstemmer_c/runtime/api.h",
    "libstemmer_c/runtime/header.h",
    "libstemmer_c/runtime/utilities.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_danish.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_danish.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_dutch.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_dutch.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_english.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_english.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_finnish.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_finnish.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_french.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_french.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_german.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_german.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_hungarian.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_hungarian.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_italian.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_italian.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_latin.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_latin.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_norwegian.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_norwegian.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_porter.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_porter.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_portuguese.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_portuguese.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_spanish.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_spanish.h",
    "libstemmer_c/src_c/stem_ISO_8859_1_swedish.c",
    "libstemmer_c/src_c/stem_ISO_8859_1_swedish.h",
    "libstemmer_c/src_c/stem_ISO_8859_2_romanian.c",
    "libstemmer_c/src_c/stem_ISO_8859_2_romanian.h",
    "libstemmer_c/src_c/stem_KOI8_R_russian.c",
    "libstemmer_c/src_c/stem_KOI8_R_russian.h",
    "libstemmer_c/src_c/stem_UTF_8_danish.c",
    "libstemmer_c/src_c/stem_UTF_8_danish.h",
    "libstemmer_c/src_c/stem_UTF_8_dutch.c",
    "libstemmer_c/src_c/stem_UTF_8_dutch.h",
    "libstemmer_c/src_c/stem_UTF_8_english.c",
    "libstemmer_c/src_c/stem_UTF_8_english.h",
    "libstemmer_c/src_c/stem_UTF_8_finnish.c",
    "libstemmer_c/src_c/stem_UTF_8_finnish.h",
    "libstemmer_c/src_c/stem_UTF_8_french.c",
    "libstemmer_c/src_c/stem_UTF_8_french.h",
    "libstemmer_c/src_c/stem_UTF_8_german.c",
    "libstemmer_c/src_c/stem_UTF_8_german.h",
    "libstemmer_c/src_c/stem_UTF_8_hungarian.c",
    "libstemmer_c/src_c/stem_UTF_8_hungarian.h",
    "libstemmer_c/src_c/stem_UTF_8_italian.c",
    "libstemmer_c/src_c/stem_UTF_8_italian.h",
    "libstemmer_c/src_c/stem_UTF_8_latin.c",
    "libstemmer_c/src_c/stem_UTF_8_latin.h",
    "libstemmer_c/src_c/stem_UTF_8_norwegian.c",
    "libstemmer_c/src_c/stem_UTF_8_norwegian.h",
    "libstemmer_c/src_c/stem_UTF_8_porter.c",
    "libstemmer_c/src_c/stem_UTF_8_porter.h",
    "libstemmer_c/src_c/stem_UTF_8_portuguese.c",
    "libstemmer_c/src_c/stem_UTF_8_portuguese.h",
    "libstemmer_c/src_c/stem_UTF_8_romanian.c",
    "libstemmer_c/src_c/stem_UTF_8_romanian.h",
    "libstemmer_c/src_c/stem_UTF_8_russian.c",
    "libstemmer_c/src_c/stem_UTF_8_russian.h",
    "libstemmer_c/src_c/stem_UTF_8_spanish.c",
    "libstemmer_c/src_c/stem_UTF_8_spanish.h",
    "libstemmer_c/src_c/stem_UTF_8_swedish.c",
    "libstemmer_c/src_c/stem_UTF_8_swedish.h",
    "libstemmer_c/src_c/stem_UTF_8_turkish.c",
    "libstemmer_c/src_c/stem_UTF_8_turkish.h",
    "test/helper.rb",
    "test/lingua/test_stemmer.rb"
  ]
  s.homepage = "http://github.com/aurelian/ruby-stemmer"
  s.licenses = ["MIT"]
  s.summary = "Expose libstemmer_c to Ruby."
  s.add_development_dependency 'rake-compiler', '~> 0.9.2'
  s.add_development_dependency 'minitest', '~> 5.5.1'
  s.add_development_dependency 'rdoc', '~> 4.2.0'
end

