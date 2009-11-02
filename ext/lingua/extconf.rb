ENV['RC_ARCHS'] = '' if RUBY_PLATFORM =~ /darwin/
require "mkmf"

ROOT = File.expand_path(File.join(File.dirname(__FILE__), '..', '..'))
LIBSTEMMER = File.join(ROOT, 'libstemmer_c')

# build libstemmer_c
# FreeBSD make is gmake
make= (RUBY_PLATFORM =~ /freebsd/)? 'gmake' : 'make'
# MacOS architecture mess up
if RUBY_PLATFORM =~ /darwin/
  begin
    ENV['ARCHFLAGS']= "-arch " + %x[file #{File.expand_path(File.join(Config::CONFIG['bindir'], Config::CONFIG['RUBY_INSTALL_NAME']))}].strip!.match(/executable (.+)$/)[1] unless ENV['ARCHFLAGS'].nil?
  rescue
    $stderr << "Failed to get your ruby executable architecture.\n"
    $stderr << "Please specify one using $ARCHFLAGS environment variable.\n"
    exit
  end
end

# make libstemmer_c. unless we're cross-compiling.
unless RUBY_PLATFORM =~ /i386-mingw32/
  system "cd #{LIBSTEMMER}; #{make} libstemmer.o; cd #{ROOT};"
  exit unless $? == 0
end

$CFLAGS  += " -I#{File.expand_path(File.join(LIBSTEMMER, 'include'))} "
$libs    += " -L#{LIBSTEMMER} #{File.expand_path(File.join(LIBSTEMMER, 'libstemmer.o'))} "

if have_header("libstemmer.h")
  create_makefile("lingua/stemmer_native")
end
