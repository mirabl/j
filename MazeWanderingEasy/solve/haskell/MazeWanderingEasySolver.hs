import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified MazeWanderingEasy (decisions)

getVars :: TC.Parser ([String])
getVars = do maze <- TC.spaces >> (TC.parseList TC.parseString)
             return (maze)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (maze) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ MazeWanderingEasy.decisions maze
            hClose hOut
    hClose hIn
