import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified ThreeTeleports (shortestDistance)

getVars :: TC.Parser (Int, Int, Int, Int, [String])
getVars = do xMe <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             yMe <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             xHome <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             yHome <- TC.spaces >> TC.parseInt ; TC.spaces >> TC.next
             teleports <- TC.spaces >> (TC.parseList TC.parseString)
             return (xMe, yMe, xHome, yHome, teleports)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (xMe, yMe, xHome, yHome, teleports) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ ThreeTeleports.shortestDistance xMe yMe xHome yHome teleports
            hClose hOut
    hClose hIn
