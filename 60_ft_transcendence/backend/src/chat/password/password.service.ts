import * as bcrypt from 'bcrypt';
import { PrismaChatService } from '../../prisma/chat/prisma.chat.service';


// export async function encodePassword(rawPassword: string) {
// 	const SALT = bcrypt.genSaltSync();
// 	return bcrypt.hashSync(rawPassword, 10);
// }

// export async function checkPassword(password: string, idOfChat: number): string {
// 	const prismaService = new PrismaChatService
// 	const passwordHashed = encodePassword(password);
// 	const passwordSaved = await prismaService.getPasswordOfChat(idOfChat);
// 	if (passwordHashed === passwordSaved) {
// 		return 'true';
// 	} else {
// 		return 'false';
// 	}
// }

