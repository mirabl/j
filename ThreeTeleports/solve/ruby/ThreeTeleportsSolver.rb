#! /usr/bin/env ruby

require_relative "ThreeTeleports"

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
  xMe = reader.next(TInt)
  reader.next()
  yMe = reader.next(TInt)
  reader.next()
  xHome = reader.next(TInt)
  reader.next()
  yHome = reader.next(TInt)
  reader.next()
  teleports = reader.next(TArray.new(TString))

  result = ThreeTeleports.new().shortestDistance(xMe, yMe, xHome, yHome, teleports)
  IO.write(ARGV[1], Writer.new.next(result, TInt).to_s)
end

init
main
