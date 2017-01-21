import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified ColorfulRoad (getMin)

getVars :: TC.Parser (String)
getVars = do road <- TC.spaces >> TC.parseString
             return (road)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (road) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ ColorfulRoad.getMin road
            hClose hOut
    hClose hIn
