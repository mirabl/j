import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified BoxesDiv2 (findSize)

getVars :: TC.Parser ([Int])
getVars = do candyCounts <- TC.spaces >> (TC.parseList TC.parseInt)
             return (candyCounts)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (candyCounts) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ BoxesDiv2.findSize candyCounts
            hClose hOut
    hClose hIn
