import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified PillarsDivTwo (maximalLength)

getVars :: TC.Parser ([Int], Int)
getVars = do height <- TC.spaces >> (TC.parseList TC.parseInt) ; TC.spaces >> TC.next
             w <- TC.spaces >> TC.parseInt
             return (height, w)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (height, w) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ PillarsDivTwo.maximalLength height w
            hClose hOut
    hClose hIn
