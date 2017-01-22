import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified RollingDiceDivTwo (minimumFaces)

getVars :: TC.Parser ([String])
getVars = do rolls <- TC.spaces >> (TC.parseList TC.parseString)
             return (rolls)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (rolls) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ RollingDiceDivTwo.minimumFaces rolls
            hClose hOut
    hClose hIn
