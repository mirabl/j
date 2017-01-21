import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified ArcadeManao (shortestLadder)

getVars :: TC.Parser ([String], Int, Int)
getVars = do level <- TC.spaces >> (TC.parseList TC.parseString) ; TC.spaces >> TC.next
             coinRow <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             coinColumn <- TC.spaces >> TC.parseInt
             return (level, coinRow, coinColumn)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (level, coinRow, coinColumn) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ ArcadeManao.shortestLadder level coinRow coinColumn
            hClose hOut
    hClose hIn
