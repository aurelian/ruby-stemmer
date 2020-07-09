ENV['RC_ARCHS'] = '' if RUBY_PLATFORM.match?(/darwin/)
require 'mkmf'

ROOT = File.expand_path(File.join(File.dirname(__FILE__), '..', '..'))
LIBSTEMMER = File.join(ROOT, 'libstemmer_c')

# build libstemmer_c
# FreeBSD make is gmake
make = RUBY_PLATFORM.match?(/freebsd/) ? 'gmake' : 'make'

# MacOS architecture mess up
if RUBY_PLATFORM.match?(/darwin/)
  # Config has been deprecated since 1.9.3, and removed since 2.2.0
  if defined?(RbConfig)
    Config = RbConfig
  end

  # see: #issue/3, #issue/5
  begin
    ENV['ARCHFLAGS'] = '-arch ' + %x[file #{File.expand_path(File.join(Config::CONFIG['bindir'], Config::CONFIG['RUBY_INSTALL_NAME']))}].strip!.match(/executable (.+)$/)[1] unless ENV['ARCHFLAGS'].nil?
  rescue
    $stderr << "Failed to get your ruby executable architecture.\n"
    $stderr << "Please specify one using $ARCHFLAGS environment variable.\n"
    exit
  end
  # see: #issue/9, #issue/6
  # see: man compat
  if ENV['COMMAND_MODE'] == 'legacy'
    $stdout << "Setting compat mode to unix2003\n."
    ENV['COMMAND_MODE'] = 'unix2003'
  end
end

# make libstemmer_c. unless we're cross-compiling.
unless RUBY_PLATFORM.match?(/i386-mingw32/)
  system "cd #{LIBSTEMMER}; #{make} libstemmer.o; cd #{ROOT};"
  exit unless $? == 0
end

$CFLAGS  += " -I#{File.expand_path(File.join(LIBSTEMMER, 'include'))} "
$libs    += " -L#{LIBSTEMMER} #{File.expand_path(File.join(LIBSTEMMER, 'libstemmer.o'))} "

create_makefile('lingua/stemmer_native') if have_header('libstemmer.h')
