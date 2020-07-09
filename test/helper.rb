require 'rubygems'
require 'bundler/setup'

require 'minitest/autorun'

$LOAD_PATH.unshift File.expand_path('../lib', __FILE__)
require 'lingua/stemmer'
