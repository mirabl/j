import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified TriangleEasy (find)

getVars :: TC.Parser (Int, [Int], [Int])
getVars = do n <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             x <- TC.spaces >> (TC.parseList TC.parseInt) ; TC.spaces >> TC.next
             y <- TC.spaces >> (TC.parseList TC.parseInt)
             return (n, x, y)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (n, x, y) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ TriangleEasy.find n x y
            hClose hOut
    hClose hIn
