import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified JumpFurther (furthest)

getVars :: TC.Parser (Int, Int)
getVars = do n <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             badStep <- TC.spaces >> TC.parseInt
             return (n, badStep)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (n, badStep) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ JumpFurther.furthest n badStep
            hClose hOut
    hClose hIn
