import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified AlphabetOrderDiv2 (isOrdered)

getVars :: TC.Parser ([String])
getVars = do words <- TC.spaces >> (TC.parseList TC.parseString)
             return (words)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (words) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ AlphabetOrderDiv2.isOrdered words
            hClose hOut
    hClose hIn
