import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified ColorfulCoinsEasy (isPossible)

getVars :: TC.Parser ([Int])
getVars = do values <- TC.spaces >> (TC.parseList TC.parseInt)
             return (values)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (values) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ ColorfulCoinsEasy.isPossible values
            hClose hOut
    hClose hIn
