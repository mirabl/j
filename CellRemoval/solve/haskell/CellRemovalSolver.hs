import System.Environment (getArgs)
import System.IO
import qualified TopCoder as TC
import qualified CellRemoval (cellsLeft)

getVars :: TC.Parser ([Int], Int)
getVars = do parent <- TC.spaces >> (TC.parseList TC.parseInt) ; TC.spaces >> TC.next
             deletedCell <- TC.spaces >> TC.parseInt
             return (parent, deletedCell)

main = do
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (TC.parse getVars "parse variables" contents) of
        Left err -> print err
        Right (parent, deletedCell) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ CellRemoval.cellsLeft parent deletedCell
            hClose hOut
    hClose hIn
