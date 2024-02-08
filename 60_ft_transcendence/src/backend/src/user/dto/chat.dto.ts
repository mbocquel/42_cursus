import {
    IsEmail,
    IsNotEmpty,
    IsOptional,
    IsString,
    Matches,
	IsNumber,
	IsBoolean,
	NotContains,
  } from 'class-validator';

/**********************API CONTROLLER****************************/
  export class PrivateConvDto {
	@IsNumber()
	idSender: number;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	loginReceiver: string;
  }

  export class SetAdminDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;

	@IsNumber()
	@IsNotEmpty()
	chatId: number;
  }

  export class UpdateDmNameDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	OldUsername: string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	newUsername: string;
  }

  export class InviteUserDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	ownerLogin: string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	username: string;

	@IsNumber()
	@IsNotEmpty()
	chat_id: number;
  }

  export class BlockUserDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	blockedLogin: string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;
  }

  export class UnblockUserDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	blockedLogin: string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;
  }

  export class IsBlockedUserDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	blockedLogin: string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;
  }

  export class BanKickLeaveDto {

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;

	@IsNumber()
	@IsNotEmpty()
	chatId: number;
  }

  export class ChangeChatTypeDto {
	@IsString()
	@IsOptional()
	password: string;

	@IsString()
	@IsNotEmpty()
	type: string;

	@IsNumber()
	@IsNotEmpty()
	chatId: number;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;
  }

  export class CreateChatDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;

	@IsString()
	@IsNotEmpty()
	chatName: string;

	@IsString()
	@IsNotEmpty()
	chatType: string;

	@IsString()
	@IsOptional()
	chatPassword: string | null;
  }

  export class JoinChatDto {
	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login: string;

	@IsNumber()
	@IsNotEmpty()
	chat_id: number;

	@IsString()
	@IsNotEmpty()
	@IsOptional()
	password: string | null;
  }
/**********************END OF API CONTROLLER****************************/

/**********************GATEWAY CONTROLLER****************************/

  export class NewChatConnectionDto {
	@IsString()
	@IsNotEmpty()
	login: string;
  }
  export class NewMessageDto {
	@IsString()
	@IsNotEmpty()
	username: string;

	@IsString()
	@IsNotEmpty()
	login: string;

	@IsBoolean()
	serviceMessage: boolean;

	@IsString()
	@IsNotEmpty()
	content: string;

	@IsNotEmpty()
	idOfChat: number;
  }

  export class SendMessageDto {
	@IsString()
	@IsNotEmpty()
	msg: string;

	@IsString()
	@IsNotEmpty()
	loginToSend: string;

	@IsNotEmpty()
	idOfUser: string;
  }

  export class RetrieveMessageDto {
	@IsNotEmpty()
	numberMsgToDisplay: number;

	@IsNotEmpty()
	chatId: number;
  }

  export class MutedUserDto {
	@IsString()
	@IsNotEmpty()
	login: string;

	@IsNotEmpty()
	chatId: number;

	@IsNumber()
	time: number;
  }

  export class ChatListOfUserDto {
	@IsString()
	@IsNotEmpty()
	login: string;
  }
