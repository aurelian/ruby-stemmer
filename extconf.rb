#
# $Id: extconf.rb 21 2008-04-30 10:57:37Z aurelian $
#

require "mkmf"

system "cd libstemmer_c; make libstemmer.o; cd #{File.dirname(__FILE__)};"

$CFLAGS  += " -I#{File.dirname(__FILE__)}/libstemmer_c/include "
$libs    += " -L#{File.dirname(__FILE__)}/libstemmer_c #{File.dirname(__FILE__)}/libstemmer_c/libstemmer.o "

# dir_config("libstemmer")

if have_header("libstemmer.h") # && have_library('libstemmer')
  create_makefile("lingua/stemmer")
end

