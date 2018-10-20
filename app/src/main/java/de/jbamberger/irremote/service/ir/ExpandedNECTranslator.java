package de.jbamberger.irremote.service.ir;

/**
 * @author Jannik Bamberger (dev.jbamberger@gmail.com)
 */

public class ExpandedNECTranslator extends CodeTranslator {

    public ExpandedNECTranslator() {
        super(new int[]{9000, 4500}, new int[]{560}, new int[]{560, 560}, new int[]{560, 1690}, 38000);
    }

    @Override
    public int[] buildCode(String codeString) {
        return buildRawCode(hexToBytes(codeString));
    }
}
