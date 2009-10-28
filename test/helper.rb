require 'rubygems'
require 'test/unit'

%w(. ../lib ../ext).each do |path|
  $LOAD_PATH.unshift(File.expand_path(File.join(File.dirname(__FILE__), path)))
end

require 'lingua/stemmer'

class Test::Unit::TestCase
end
