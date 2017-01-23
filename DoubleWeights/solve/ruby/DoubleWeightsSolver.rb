#! /usr/bin/env ruby

require_relative "DoubleWeights"

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
  weight1 = reader.next(TArray.new(TString))
  reader.next()
  weight2 = reader.next(TArray.new(TString))

  result = DoubleWeights.new().minimalCost(weight1, weight2)
  IO.write(ARGV[1], Writer.new.next(result, TInt).to_s)
end

init
main
