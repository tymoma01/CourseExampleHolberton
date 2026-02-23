import prisma from "../config/database";
import { DatabaseError } from "../utils/errors";

interface QuestionData {
	question: string;
	embedding: number[];
	questionIndex: number;
}


class DocumentQuestionModel {
	static async createMany(docId: string, questionsData: QuestionData[]): Promise<void> {
		try {
			// Use raw SQL for unsupported vector type
			for (const item of questionsData) {
				const embeddingString = `[${item.embedding.join(',')}]`;
				const now = new Date();
				
				await prisma.$executeRaw`
					INSERT INTO document_questions (id, doc_id, question, embedding, question_index, created_at)
					VALUES (${`${docId}_question_${item.questionIndex}`}, ${docId}::uuid, ${item.question}, ${embeddingString}::vector, ${item.questionIndex}, ${now})
					ON CONFLICT (doc_id, question_index) DO UPDATE SET
						question = EXCLUDED.question,
						embedding = EXCLUDED.embedding,
						created_at = EXCLUDED.created_at
				`;
			}
		} catch (error) {
			throw new DatabaseError(
				`Failed to create document questions for docId: ${docId}`,
				error as Error
			);
		}
	}

	static async getDocumentQuestions(docId: string): Promise<string[]> {
		try {
			const questions = await prisma.documentQuestions.findMany({
				where: { docId },
				select: { question: true },
				orderBy: { questionIndex: 'asc' }
			});

			return questions.map(q => q.question);
		} catch (error) {
			throw new DatabaseError(
				`Failed to fetch questions for docId: ${docId}`,
				error as Error
			);
		}
	}
}

export { QuestionData };
export default DocumentQuestionModel;