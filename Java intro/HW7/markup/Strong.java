package markup;
import java.util.List;

public class Strong extends AbstractElements {
	public void toHtml(StringBuilder str) {
		inH(str, "strong");
	}
	public void toTex(StringBuilder str) {
		inT(str, "\\textbf");
	}
	public Strong(List <threeAble> list) {
		this.list = list;
	}
	public void toMarkdown(StringBuilder str) {
		inM(str, "__");
	}
}