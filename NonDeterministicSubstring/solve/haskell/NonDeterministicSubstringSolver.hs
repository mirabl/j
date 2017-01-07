import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified NonDeterministicSubstring (ways)

getVars :: TC.Parser (String, String)
getVars = do a <- TC.spaces >> TC.parseString ; TC.spaces >> TC.next
             b <- TC.spaces >> TC.parseString
             return (a, b)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (a, b) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ NonDeterministicSubstring.ways a b
            hClose hOut
    hClose hIn
