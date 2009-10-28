ENV['RC_ARCHS'] = '' if RUBY_PLATFORM =~ /universal-darwin/
require "mkmf"

# build libstemmer_c
ENV['ARCHFLAGS']= "-arch #{Config::CONFIG['host_cpu']}" if RUBY_PLATFORM =~ /darwin/
ENV['ARCHFLAGS']= "-arch x86_64" if Config::CONFIG['host_cpu'] == 'i686' && RUBY_PLATFORM =~ /darwin/

system "cd libstemmer_c; make libstemmer.o; cd #{File.dirname(__FILE__)};"

$CFLAGS  += " -I#{File.join(File.dirname(__FILE__),'libstemmer_c','include')} "
$libs    += " -L#{File.join(File.dirname(__FILE__),'libstemmer_c')} #{File.join(File.dirname(__FILE__),'libstemmer_c','libstemmer.o')} "

# dir_config("libstemmer")

if have_header("libstemmer.h") # && have_library('libstemmer')
  create_makefile("lingua/stemmer")
end

