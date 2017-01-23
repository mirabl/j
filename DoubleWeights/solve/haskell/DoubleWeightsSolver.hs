import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified DoubleWeights (minimalCost)

getVars :: TC.Parser ([String], [String])
getVars = do weight1 <- TC.spaces >> (TC.parseList TC.parseString) ; TC.spaces >> TC.next
             weight2 <- TC.spaces >> (TC.parseList TC.parseString)
             return (weight1, weight2)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (weight1, weight2) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ DoubleWeights.minimalCost weight1 weight2
            hClose hOut
    hClose hIn
