#! /usr/bin/env ruby

require_relative "NonDeterministicSubstring"

require "gettc/types"
include Gettc

def init
  gettc_home = File.expand_path(ENV["GETTC_HOME"] || File.join(ENV["HOME"], ".gettc"))
  $LOAD_PATH << File.join(gettc_home, "include", "ruby")
  require "topcoder"
  include TopCoder
end

def main
  reader = Reader.new(IO.read(ARGV[0]))
  A = reader.next(TString)
  reader.next()
  B = reader.next(TString)

  result = NonDeterministicSubstring.new().ways(A, B)
  IO.write(ARGV[1], Writer.new.next(result, TLong).to_s)
end

init
main
