import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified Quorum (count)

getVars :: TC.Parser ([Int], Int)
getVars = do arr <- TC.spaces >> (TC.parseList TC.parseInt) ; TC.spaces >> TC.next
             k <- TC.spaces >> TC.parseInt
             return (arr, k)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (arr, k) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ Quorum.count arr k
            hClose hOut
    hClose hIn
