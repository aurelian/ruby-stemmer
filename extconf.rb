ENV['RC_ARCHS'] = '' if RUBY_PLATFORM =~ /darwin/

require "mkmf"
arch = ""
unless RUBY_PLATFORM =~ /universal/
  arch = "export ARCHFLAGS=' -arch #{RUBY_PLATFORM.split("-")[0]}';"
end

system "#{arch}cd libstemmer_c; make libstemmer.o; cd #{File.dirname(__FILE__)};"

$CFLAGS  += " -I#{File.join(File.dirname(__FILE__),'libstemmer_c','include')} "
$libs    += " -L#{File.join(File.dirname(__FILE__),'libstemmer_c')} #{File.join(File.dirname(__FILE__),'libstemmer_c','libstemmer.o')} "

# dir_config("libstemmer")

if have_header("libstemmer.h") # && have_library('libstemmer')
  create_makefile("lingua/stemmer")
end

