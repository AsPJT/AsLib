//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_INVENTORY
#define INCLUDED_AS_PROJECT_LIBRARY_INVENTORY


namespace AsLib
{
	//アイテムデータを管理する
	struct Item {
		size_t type{};
		AsTexture* texture{ nullptr };
		size_t stack_max{};
		std::string name{};
		Item() = default;
		Item(const size_t type_, AsTexture& t_, const size_t stack_, const char* const name_) :type(type_), texture(&t_), stack_max(stack_), name(name_) {}
		Item(AsTexture* const t_, const size_t stack_, const char* const name_) :type(0), texture(t_), stack_max(stack_), name(name_) {}
		Item(const size_t type_, AsTexture& t_, const char* const name_) :type(type_), texture(&t_), stack_max(1), name(name_) {}
		Item(AsTexture* const t_, const char* const name_) :type(0), texture(t_), stack_max(1), name(name_) {}
	};

	struct UniqueItem {
		size_t item{};
		size_t stack{};
		UniqueItem() = default;
		constexpr UniqueItem(const size_t item_, const size_t stack_) :item(item_), stack(stack_) {}

		//ソート用
		bool operator<(const UniqueItem& right_) const noexcept { return item == right_.item ? stack < right_.stack : item < right_.item; }
		bool operator>(const UniqueItem& left_) const noexcept { return item == left_.item ? stack > left_.stack : item > left_.item; }
	};

	constexpr UniqueItem aslib_unique_item_init;

	//持っているアイテムのデータを管理する
	//sizeが収納可能最大サイズ
	struct ShareItem {
		std::vector<UniqueItem> unique{};

		ShareItem() = default;
		ShareItem(const size_t max_) {
			const size_t before_size{ unique.size() };
			unique.resize(max_);
			for (size_t i{ before_size }; i < max_; ++i) {
				unique[i].item = 0;
				unique[i].stack = 0;
			}
		}

		ShareItem& setSize(const size_t max_) noexcept {
			const size_t before_size{ unique.size() };
			unique.resize(max_);
			for (size_t i{ before_size }; i < max_; ++i) {
				unique[i].item = 0;
				unique[i].stack = 0;
		}
			return *this;
	}

		ShareItem& addSize(const int32_t add_) noexcept {
			const size_t before_size{ unique.size() };
			const size_t total_size{ ((int32_t(unique.size()) + add_) < 0) ? 0 : size_t((before_size + add_)) };
			unique.resize(total_size);
			for (size_t i{ before_size }; i < total_size; ++i) {
				unique[i].item = 0;
				unique[i].stack = 0;
			}
			return *this;
		}

#if !defined(__ANDROID__)
		ShareItem& sortUp() noexcept { sort(unique.begin(), unique.end()); return *this; }
		ShareItem& sortDown() noexcept { sort(unique.begin(), unique.end(), std::greater<UniqueItem>()); return *this; }
#else
		ShareItem& sortUp() { return *this; }
		ShareItem& sortDown() { return *this; }
#endif
		size_t size() const noexcept { return unique.size(); }
		ShareItem& push(const size_t id_, const size_t item_, const size_t stack_ = 1) noexcept {
			unique[id_].item = item_;
			unique[id_].stack = stack_;
			return *this;
		}
		ShareItem& push(const size_t id_, const UniqueItem& item_) noexcept {
			unique[id_].item = item_.item;
			unique[id_].stack = item_.stack;
			return *this;
		}
		//新しいアイテムを追加する
		UniqueItem add(const size_t item_, const size_t stack_,const size_t max_) noexcept {
			size_t add_stack{ stack_ };
			size_t s{};
			for (size_t i{}; i < unique.size(); ++i) {
				if (unique[i].item == item_ || unique[i].item == 0) {
					unique[i].item = item_;
					s = max_ - unique[i].stack;
					if (s >= add_stack) {
						unique[i].stack += add_stack;
						return UniqueItem(item_, 0);
					}
					else {
						unique[i].stack += s;
						add_stack -= s;
					}
				}
				if (add_stack == 0) return UniqueItem(item_, 0);
			}
			return UniqueItem(item_, add_stack);
		}
		UniqueItem add(const UniqueItem& item_, const size_t max_) noexcept { return add(item_.item, item_.stack, max_); }

		//中身を消去する
		UniqueItem clear(const size_t id_) noexcept {
			if (id_ >= unique.size()) return aslib_unique_item_init;
			const UniqueItem unique_item(unique[id_].item, unique[id_].stack);
			unique[id_].item = 0;
			unique[id_].stack = 0;
			return unique_item;
		}
	};
	//インベントリ機能を管理する
	struct Inventory {
		AsTexture* frame{ nullptr };
		AsTexture* select_frame_texture{ nullptr };
		AsFont* font{ nullptr };
		ShareItem* share_item{ nullptr };
		PosA4 pos{};
		size_t num_frame{};
		size_t select_frame{};

		Inventory(AsTexture& frame_, AsTexture& select_frame_texture, AsFont& font_, ShareItem& share_, const PosA4& pos_, const size_t num_frame_, const size_t select_frame_)
			:frame(&frame_), select_frame_texture(&select_frame_texture), font(&font_), share_item(&share_), pos(pos_), num_frame(num_frame_), select_frame(select_frame_) {}
		UniqueItem itemClear() noexcept { return (share_item == nullptr) ? aslib_unique_item_init : share_item->clear(select_frame); }
		Inventory& selectAdd(const int32_t add_) noexcept {
			select_frame = (add_ + select_frame + num_frame) % num_frame;
			return *this;
		}
		Inventory& isSelectUp(const bool is_up_) noexcept { if (is_up_) select_frame = (select_frame + 1) % num_frame; return *this; }
		Inventory& isSelectDown(const bool is_down_) noexcept { if (is_down_) select_frame = (select_frame + num_frame - 1) % num_frame; return *this; }
		Inventory& draw(const std::vector<Item>& item_) noexcept {
			if (frame == nullptr || font == nullptr || share_item == nullptr || select_frame_texture == nullptr) return *this;

			PosA4 draw_pos(pos);
			draw_pos.h = draw_pos.w;
			draw_pos.x = pos.x - (int32_t(num_frame * pos.w) - pos.w) / 2;
			for (size_t i{}; i < num_frame; ++i) {
				if (select_frame == i) select_frame_texture->draw(Pos4(draw_pos));
				else frame->draw(draw_pos);

				if (i < share_item->size() && share_item->unique[i].item < item_.size() && share_item->unique[i].item != 0) {
					item_[share_item->unique[i].item].texture->draw(draw_pos);
					font->draw(draw_pos, "%d", share_item->unique[i].stack);
				}
				draw_pos.x += draw_pos.w;
			}
			return *this;
		}

		Inventory& addSize(const int32_t add_) noexcept {
			if (share_item == nullptr) return *this;
			share_item->addSize(add_);
			num_frame = ((int32_t(num_frame) + add_) < 0) ? 0 : size_t((num_frame + add_));
			return *this;
		}

	};

}

#endif //Included AsProject Library