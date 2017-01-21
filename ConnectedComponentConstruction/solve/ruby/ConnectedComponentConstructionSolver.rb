#! /usr/bin/env ruby

require_relative "ConnectedComponentConstruction"

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
  s = reader.next(TArray.new(TInt))

  result = ConnectedComponentConstruction.new().construct(s)
  IO.write(ARGV[1], Writer.new.next(result, TArray.new(TString)).to_s)
end

init
main
