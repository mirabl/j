import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified ConnectedComponentConstruction (construct)

getVars :: TC.Parser ([Int])
getVars = do s <- TC.spaces >> (TC.parseList TC.parseInt)
             return (s)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (s) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ ConnectedComponentConstruction.construct s
            hClose hOut
    hClose hIn
