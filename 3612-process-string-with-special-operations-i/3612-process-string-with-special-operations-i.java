class Solution {
    public String processStr(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c: s.toCharArray()) {
            if (Character.isLowerCase(c)){
                sb.append(c);
            }
            if (c == '*') {
                if (!sb.isEmpty()) {
                    sb.setLength(sb.length() - 1);
                }
            }
            if(c == '#'){
                sb.append(sb);
            } 
            if(c == '%'){
                sb.reverse();
            } 
        }

        return sb.toString();
    }
}