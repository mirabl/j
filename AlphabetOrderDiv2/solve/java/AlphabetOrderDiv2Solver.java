import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class AlphabetOrderDiv2Solver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> wordsBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] words = new String[wordsBoxed.size()];
        for (int _i = 0; _i < wordsBoxed.size(); ++_i)
            words[_i] = wordsBoxed.get(_i);
        reader.close();

        AlphabetOrderDiv2 solver = new AlphabetOrderDiv2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.isOrdered(words));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
