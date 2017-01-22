#! /usr/bin/env ruby

require_relative "JumpFurther"

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
  N = reader.next(TInt)
  reader.next()
  badStep = reader.next(TInt)

  result = JumpFurther.new().furthest(N, badStep)
  IO.write(ARGV[1], Writer.new.next(result, TInt).to_s)
end

init
main
