import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified Fragile2 (countPairs)

getVars :: TC.Parser ([String])
getVars = do graph <- TC.spaces >> (TC.parseList TC.parseString)
             return (graph)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (graph) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ Fragile2.countPairs graph
            hClose hOut
    hClose hIn
