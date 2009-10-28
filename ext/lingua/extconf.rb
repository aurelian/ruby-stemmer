ENV['RC_ARCHS'] = '' if RUBY_PLATFORM =~ /universal-darwin/
require "mkmf"

ROOT = File.expand_path(File.join(File.dirname(__FILE__), '..', '..'))
LIBSTEMMER = File.join(ROOT, 'libstemmer_c')

# build libstemmer_c
ENV['ARCHFLAGS']= "-arch #{Config::CONFIG['host_cpu']}" if RUBY_PLATFORM =~ /darwin/
ENV['ARCHFLAGS']= "-arch x86_64" if Config::CONFIG['host_cpu'] == 'i686' && RUBY_PLATFORM =~ /darwin/
system "cd #{LIBSTEMMER}; make libstemmer.o; cd #{ROOT};"

$CFLAGS  += " -I#{File.join(LIBSTEMMER, 'include')} "
$libs    += " -L#{LIBSTEMMER} #{File.join(LIBSTEMMER, 'libstemmer.o')} "

if have_header("libstemmer.h")
  create_makefile("lingua/stemmer_native")
end
